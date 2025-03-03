// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuppeeData.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EMoneyType : uint8
{
	BLUE,
	GOLD,
	GREEN,
	RED,
	SILVER,
	MAX_VALUE UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FMoneyData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMoneyType MoneyType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> RupeeIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UStaticMesh> RupeeMesh;
};