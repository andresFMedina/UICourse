// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewModels/UVMMAinHUD.h"
#include "Kismet/GameplayStatics.h"
#include "UICourse/UICourseCharacter.h"
#include "Components/InventoryComponent.h"

const bool UUVMMAinHUD::GetShowWidget() const
{
	return bShowWidget;
}

void UUVMMAinHUD::SetShowWidget(const bool ShowWidget)
{
	UE_MVVM_SET_PROPERTY_VALUE(bShowWidget, ShowWidget);
}

void UUVMMAinHUD::Init()
{
	auto CurrentPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	auto PlayerCharacter = Cast<AUICourseCharacter>(CurrentPawn);
	if (PlayerCharacter)
	{
		auto PlayerInventory = PlayerCharacter->GetInventoryComponent();		
		PlayerInventory->OnInventoryToggleDelegate.AddDynamic(this, &ThisClass::SetShowWidget);
	}
}
