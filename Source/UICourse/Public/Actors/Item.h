// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/ItemInventory.h"
#include "Interfaces/Interactable.h"
#include "Item.generated.h"

class UStaticMeshComponent;
class USphereComponent;
UCLASS()
class UICOURSE_API AItem : public AActor, public IInteractable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	FItemSlot ItemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FName ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereCollider;	
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE const FName& GetItemId() { return ItemId; }
	FORCEINLINE const FItemSlot& GetItemInfo() { return ItemInfo; }

	virtual void Interact() override;

	virtual const FText& GetName() const override;

};
