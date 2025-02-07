// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/MainMenuWidget.h"

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
		return;
	}

	MainMenuWidget->RemoveFromParent();
	FInputModeGameOnly InputMode;
	PlayerController->SetInputMode(InputMode);
	PlayerController->SetShowMouseCursor(false);
	bIsShowingMainMenu = false;
	MainMenuWidget = nullptr;
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
