// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/MainPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainPlayerController::BeginPlay()
{
	check(MainHUDClass);

	MainHUD = CreateWidget<UUserWidget>(this, MainHUDClass);
	check(MainHUD);

	MainHUD->AddToViewport();
	MainHUD->SetVisibility(ESlateVisibility::Visible);

	
}
