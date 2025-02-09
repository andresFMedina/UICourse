// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemInventory.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	SWORD,
	SHIELD,
	CONSUMABLE
};

USTRUCT(BlueprintType)
struct FInventoryItemRow : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StackSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UStaticMesh> Mesh;
};
