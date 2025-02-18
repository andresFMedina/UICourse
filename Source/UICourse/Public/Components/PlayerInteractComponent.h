// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/ItemInventory.h"
#include "PlayerInteractComponent.generated.h"

class UItemPickupWidget;
class IInteractable;
class UWidgetComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemInteracted, FItemSlot, Interactable);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UICOURSE_API UPlayerInteractComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Widgets, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UItemPickupWidget> PickupWidgetSubclass;	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Widgets, meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* PickupWidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Trace, meta = (AllowPrivateAccess = "true"))
	float TraceDistance;

	UItemPickupWidget* RenderInteractWidget();

	void TraceItem();

	IInteractable* Interactable;

public:	
	// Sets default values for this component's properties
	UPlayerInteractComponent();

	FOnItemInteracted OnInteractedDelegate;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Interact();
		
};
