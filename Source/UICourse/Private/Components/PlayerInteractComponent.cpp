// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PlayerInteractComponent.h"
#include "Interfaces/Interactable.h"
#include "Components/WidgetComponent.h"
#include "Widgets/ItemPickupWidget.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Actors/Item.h"



UItemPickupWidget* UPlayerInteractComponent::RenderInteractWidget()
{
	if (Interactable) 
	{
		auto InteractWidget = CreateWidget<UItemPickupWidget>(GetWorld(), PickupWidgetSubclass);
		PickupWidgetComponent->SetWidget(InteractWidget);
		InteractWidget->SetText(Interactable->GetName());

		return InteractWidget;
	}

	PickupWidgetComponent->SetWidget(nullptr);
	return nullptr;
}

void UPlayerInteractComponent::TraceItem()
{
	if (GetOwner()) 
	{
		FVector Start = GetOwner()->GetActorLocation() - FVector(0,0,80.f);
		FVector ForwardVector = GetOwner()->GetActorForwardVector();
		FVector End = Start + (ForwardVector * TraceDistance);

		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(GetOwner());

		bool bDidHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);

		if (bDidHit)
		{
			auto HitActor = HitResult.GetActor();
			if (HitActor->Implements<UInteractable>())
			{
				Interactable = Cast<IInteractable>(HitActor);				
				RenderInteractWidget();				
			}
		}
		else 
		{
			Interactable = nullptr;
			RenderInteractWidget();
		}		

		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.2f, 0, 1.0f);
	}
}

// Sets default values for this component's properties
UPlayerInteractComponent::UPlayerInteractComponent() : 
	TraceDistance(300.f)	
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;	
}


// Called when the game starts
void UPlayerInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	
	PickupWidgetComponent = NewObject<UWidgetComponent>(GetOwner(), UWidgetComponent::StaticClass());
	if (PickupWidgetComponent)
	{
		PickupWidgetComponent->SetupAttachment(GetOwner()->GetRootComponent());
		PickupWidgetComponent->RegisterComponent();
		PickupWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
		PickupWidgetComponent->SetDrawSize(FVector2D(250.f, 30));
	}
}


// Called every frame
void UPlayerInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TraceItem();
}

void UPlayerInteractComponent::Interact()
{
	if (Interactable) 
	{
		auto Item = Cast<AItem>(Interactable);
		if (Item) OnInteractedDelegate.Broadcast(Item->GetItemInfo());
		Interactable->Interact();
	}
}
