// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UMainMenuWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UICOURSE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UMainMenuWidget> MainMenuSubclass;

	UMainMenuWidget* MainMenuWidget;

	bool bIsShowingMainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	int MoneyAmount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;	

public:		
	void ToggleInventory();
	
	FORCEINLINE int32 GetMoneyAmount() const { return MoneyAmount; }

	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }
};
