// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUDWidget.generated.h"

class UItemPickupWidget;
class UHealthWidget;
/**
 * 
 */
UCLASS()
class UICOURSE_API UMainHUDWidget : public UUserWidget
{
	GENERATED_BODY()

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UItemPickupWidget* InteractWidget;*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UHealthWidget* HealthBarWidget;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta =  (AllowPrivateAccess = "true"))
	bool bShowMainHud;

public:
	FORCEINLINE const bool ShouldShowMainHud() const { return bShowMainHud; }
	FORCEINLINE void SetShowMainHud(const bool ShowMainHud) { bShowMainHud = ShowMainHud; }

};
