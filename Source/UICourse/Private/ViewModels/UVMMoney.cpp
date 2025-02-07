// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewModels/UVMMoney.h"
#include "Kismet/GameplayStatics.h"
#include "UICourse/UICourseCharacter.h"
#include "Components/InventoryComponent.h"


void UUVMMoney::Init()
{
	auto CurrentPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	auto PlayerCharacter = Cast<AUICourseCharacter>(CurrentPawn);
	if (PlayerCharacter)
	{
		auto PlayerInventory = PlayerCharacter->GetInventoryComponent();
		SetCurrentMoney(PlayerInventory->GetMoneyAmount());
		PlayerInventory->OnMoneyChangeDelegate.AddDynamic(this, &ThisClass::OnMoneyChanged);
	}
}

void UUVMMoney::OnMoneyChanged(int32 NewAmount)
{
	SetCurrentMoney(NewAmount);
}

int32 UUVMMoney::GetCurrentMoney() const
{
	return CurrentMoney;
}

void UUVMMoney::SetCurrentMoney(const int32 NewAmount)
{
	UE_MVVM_SET_PROPERTY_VALUE(CurrentMoney, NewAmount);
}


