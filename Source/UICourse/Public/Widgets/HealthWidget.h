// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthWidget.generated.h"

class UWrapBox;
class UHeartWidget;
/**
 * 
 */
UCLASS()
class UICOURSE_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UWrapBox* HeartsBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = ( AllowPrivateAccess = "true"))
	TSubclassOf<UHeartWidget> HeartWidgetSubclass;

	
	

	void SetHealthBox();

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(const float NewMaxHealth);

	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(const float NewCurrentHealth);
};
