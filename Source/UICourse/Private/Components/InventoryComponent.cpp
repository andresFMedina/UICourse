// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/MainMenuWidget.h"
#include "Data/ItemInventory.h"
#include "Model/ItemInventoryModel.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	MaxHealth = 5;
	CurrentHealth = MaxHealth;
	MoneyAmount = 0;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

UItemInventoryModel* UInventoryComponent::FindExistingItemByName(const FName ItemName) const
{
	if (!InventoryItems.IsEmpty()) {
		auto ItemFound = InventoryItems.FindByPredicate([&ItemName](UItemInventoryModel* Item)
			{
				return Item->GetItemInfo()->ItemRow.RowName == ItemName && Item->GetItemInfo()->ItemQuantity < Item->GetItemInfo()->ItemRow.GetRow<FInventoryItemRow>("")->StackSize;
			});
		return ItemFound ? *ItemFound : nullptr;
	}
	return nullptr;
}

void UInventoryComponent::ToggleInventory()
{
	auto PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!bIsShowingMainMenu)
	{
		MainMenuWidget = CreateWidget<UMainMenuWidget>(PlayerController, MainMenuSubclass);
		MainMenuWidget->AddToViewport();
		FInputModeGameAndUI InputMode;
		InputMode.SetWidgetToFocus(MainMenuWidget->TakeWidget());
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

		PlayerController->SetInputMode(InputMode);
		PlayerController->SetShowMouseCursor(true);
		bIsShowingMainMenu = true;
		OnInventoryToggleDelegate.Broadcast(true);
		return;
	}

	MainMenuWidget->RemoveFromParent();
	FInputModeGameOnly InputMode;
	PlayerController->SetInputMode(InputMode);
	PlayerController->SetShowMouseCursor(false);
	bIsShowingMainMenu = false;
	MainMenuWidget = nullptr;
	OnInventoryToggleDelegate.Broadcast(false);
}

void UInventoryComponent::AddMoney(const int32 NewMoneyAmount)
{
	MoneyAmount += NewMoneyAmount;
	OnMoneyChangeDelegate.Broadcast(MoneyAmount);
}

void UInventoryComponent::SetMaxHealth(const float NewMaxHealth)
{
	MaxHealth += NewMaxHealth;
	OnMaxHealthChangeDelegate.Broadcast(NewMaxHealth);
}

void UInventoryComponent::SetCurrentHealth(const float NewCurrentHealth)
{
	CurrentHealth += NewCurrentHealth;
	OnCurrentHealthChangeDelegate.Broadcast(CurrentHealth);
}

void UInventoryComponent::AddItem(FItemSlot NewItemSlot)
{
	FName& RowName = NewItemSlot.ItemRow.RowName;
	UItemInventoryModel* ExistingItem = FindExistingItemByName(RowName);
	if (!ExistingItem) 
	{
		return CreateSlot(NewItemSlot);
	}

	auto ItemInfo = ExistingItem->GetItemInfo();
	int16 AvaliableSlotItems = ItemInfo->ItemRow.GetRow<FInventoryItemRow>("")->StackSize - ItemInfo->ItemQuantity;
	if (AvaliableSlotItems >= NewItemSlot.ItemQuantity)
	{
		ExistingItem->AddStackToItem(NewItemSlot.ItemQuantity);
		return;
	}
	int16 RemainingItems = NewItemSlot.ItemQuantity - AvaliableSlotItems;
	ExistingItem->AddStackToItem(AvaliableSlotItems);

	if (RemainingItems > 0)
	{
		NewItemSlot.ItemQuantity = RemainingItems;
		CreateSlot(NewItemSlot);
	}

}

void UInventoryComponent::CreateSlot(FItemSlot& NewItemSlot)
{
	auto NewItem = NewObject<UItemInventoryModel>();
	NewItem->SetItemInfo(NewItemSlot);
	InventoryItems.Add(NewItem);
	return;
}
