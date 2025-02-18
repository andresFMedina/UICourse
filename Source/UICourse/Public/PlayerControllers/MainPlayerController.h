// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UICOURSE_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> MainHUDClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD", meta = (AllowPrivateAccess = "true"))
	UUserWidget* MainHUD;
	
};
