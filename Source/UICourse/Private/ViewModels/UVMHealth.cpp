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
		SetMaxHealth(PlayerCharacter->GetInventoryComponent()->GetMaxHealth());
		SetCurrentHealth(PlayerCharacter->GetInventoryComponent()->GetCurrentHealth());
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
	MaxHealth = NewMaxHealth;
}

void UUVMHealth::SetCurrentHealth(const float NewCurrentHealth)
{
	CurrentHealth = NewCurrentHealth;
}
