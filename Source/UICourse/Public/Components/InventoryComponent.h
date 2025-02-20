// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoneyChange, int32, MoneyAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChange, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentHealthChange, float, NewCurrentHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryToggle, bool, ShowMainHud);

class UMainMenuWidget;
class UItemInventoryModel;
struct FItemSlot;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	TArray<UItemInventoryModel*> InventoryItems;

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(BlueprintReadOnly)
	FOnMoneyChange OnMoneyChangeDelegate;

	UPROPERTY(BlueprintReadOnly)
	FOnMaxHealthChange OnMaxHealthChangeDelegate;

	UPROPERTY(BlueprintReadOnly)
	FOnCurrentHealthChange OnCurrentHealthChangeDelegate;

	UPROPERTY(BlueprintReadOnly)
	FOnInventoryToggle OnInventoryToggleDelegate;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;	

private:
	UItemInventoryModel* FindExistingItemByName(const FName ItemName) const;

	void CreateSlot(FItemSlot& NewItemSlot);

public:		
	void ToggleInventory();
	
	FORCEINLINE int32 GetMoneyAmount() const { return MoneyAmount; }

	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }

	FORCEINLINE const TArray<UItemInventoryModel*> GetInventoryItems() const { return InventoryItems; }

	UFUNCTION(BlueprintCallable)
	void AddMoney(const int32 NewMoneyAmount);

	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(const float NewMaxHealth);

	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(const float NewCurrentHealth);

	UFUNCTION(BlueprintCallable)
	void AddItem(FItemSlot NewItem);
};
