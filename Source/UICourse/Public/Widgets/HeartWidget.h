// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeartWidget.generated.h"

/**
 *
 */
class UImage;

UCLASS()
class UICOURSE_API UHeartWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UImage* HeartIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UTexture2D* FullHeartIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UTexture2D* HalfHeartIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UTexture2D* EmptyHeartIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Setter)
	float Percent = 0.f;

	void SetIconByPercent();

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;


public:
	void SetPercent(const float NewPercent);
};
