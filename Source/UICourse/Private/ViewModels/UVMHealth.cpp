// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewModels/UVMHealth.h"
#include "Kismet/GameplayStatics.h"
#include "UICourse/UICourseCharacter.h"
#include "Components/InventoryComponent.h"


void UUVMHealth::Init()
{
	auto CurrentPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	auto PlayerCharacter = Cast<AUICourseCharacter>(CurrentPawn);
	if (PlayerCharacter)
	{
		auto PlayerInventory = PlayerCharacter->GetInventoryComponent();
		SetMaxHealth(PlayerInventory->GetMaxHealth());
		SetCurrentHealth(PlayerInventory->GetCurrentHealth());
		PlayerInventory->OnMaxHealthChangeDelegate.AddDynamic(this, &ThisClass::SetMaxHealth);
		PlayerInventory->OnCurrentHealthChangeDelegate.AddDynamic(this, &ThisClass::SetCurrentHealth);
		
	}
}

float UUVMHealth::GetMaxHealth() const
{
	return MaxHealth;
}

float UUVMHealth::GetCurrentHealth() const
{
	return CurrentHealth;
}

void UUVMHealth::SetMaxHealth(const float NewMaxHealth)
{
	UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, NewMaxHealth);	
}

void UUVMHealth::SetCurrentHealth(const float NewCurrentHealth)
{
	UE_MVVM_SET_PROPERTY_VALUE(CurrentHealth, NewCurrentHealth);
}
