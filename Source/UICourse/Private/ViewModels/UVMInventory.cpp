// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewModels/UVMInventory.h"
#include "Kismet/GameplayStatics.h"
#include "UICourse/UICourseCharacter.h"
#include "Data/ItemInventory.h"
#include "Model/ItemInventoryModel.h"
#include "Components/InventoryComponent.h"
#include "ViewModels/UVMInventoryEntryItem.h"

void UUVMInventory::Init()
{
	auto CurrentPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	auto PlayerCharacter = Cast<AUICourseCharacter>(CurrentPawn);
	if (PlayerCharacter)
	{

		auto PlayerInventory = PlayerCharacter->GetInventoryComponent();
		InventoryItemsByType.Add(EItemType::SWORD, FInventoryByCategory());
		InventoryItemsByType.Add(EItemType::SHIELD, FInventoryByCategory());
		InventoryItemsByType.Add(EItemType::CONSUMABLE, FInventoryByCategory());

		auto AllItems = PlayerInventory->GetInventoryItems();
		for (auto& Items : InventoryItemsByType)
		{
			auto ItemType = Items.Key;
			Items.Value.InventoryItems = AllItems.FilterByPredicate([ItemType](UItemInventoryModel* Item)
				{
					return ItemType == Item->GetItemInfo()->ItemType;
				});
		}
		SetSelectedItemType(EItemType::CONSUMABLE);
		OnItemUseDelegate.AddDynamic(PlayerInventory, &UInventoryComponent::UseItem);
		OnDropItemDelegate.AddDynamic(PlayerInventory, &UInventoryComponent::DropItem);
		RightHandItem = PlayerInventory->GetRightHandItem();
		LeftHandItem = PlayerInventory->GetLeftHandItem();		
	}
}

const TArray<UItemInventoryModel*> UUVMInventory::GetListByItemType() const
{
	if (InventoryItemsByType.Num() > 0)
		return InventoryItemsByType[SelectedItemType].InventoryItems;
	return TArray<UItemInventoryModel*>();
}

const EItemType UUVMInventory::GetSelectedItemType() const
{
	return SelectedItemType;
}

void UUVMInventory::SetSelectedItemType(const EItemType ItemType)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(SelectedItemType, ItemType))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetListByItemType);
	}
}

void UUVMInventory::UseItem(UItemInventoryModel* ItemToUse)
{
	OnItemUseDelegate.Broadcast(ItemToUse);
	switch (ItemToUse->GetItemInfo()->ItemType)
	{
	case EItemType::CONSUMABLE:
		ChangeItemQuantity(ItemToUse);
		break;
	case EItemType::SWORD:
		if (RightHandItem) ItemViewModels[RightHandItem]->SetIsEquipped(false);
		RightHandItem = ItemToUse;
		EquipItem(ItemToUse);
		break;
	case EItemType::SHIELD:
		if (LeftHandItem) ItemViewModels[LeftHandItem]->SetIsEquipped(false);
		LeftHandItem = ItemToUse;
		EquipItem(ItemToUse);
		break;
	default:
		break;
	}
}

void UUVMInventory::DropItem(UItemInventoryModel* ItemToDrop)
{
	ChangeItemQuantity(ItemToDrop);
	OnDropItemDelegate.Broadcast(ItemToDrop);

}

void UUVMInventory::ChangeItemQuantity(UItemInventoryModel* ItemToRemove)
{
	ItemToRemove->RemoveStackToItem(1);
	if (ItemToRemove->GetItemInfo()->ItemQuantity <= 0)
	{
		OnRemoveListItemDelegate.Broadcast(ItemToRemove);
		return;
	}

	auto ItemViewModel = ItemViewModels[ItemToRemove];
	if (ItemViewModel)
	{
		ItemViewModel->SetItemQuantity(ItemToRemove->GetItemInfo()->ItemQuantity);
	}
}

void UUVMInventory::EquipItem(UItemInventoryModel* ItemToEquip)
{

	auto ItemViewModel = ItemViewModels[ItemToEquip];
	if (ItemViewModel)
	{
		ItemViewModel->SetIsEquipped(true);
	}
}
