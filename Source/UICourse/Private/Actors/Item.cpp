// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Item.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DataTable.h"

// Sets default values
AItem::AItem() :
	ItemId(FString("Apple"))
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));	

	SetRootComponent(StaticMesh);
	SphereCollider = CreateDefaultSubobject<USphereComponent>(FName("SphereCollider"));
	SphereCollider->SetupAttachment(StaticMesh);
	//SphereCollider->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

}

void AItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	auto InventoryItem = ItemInfo.ItemRow.GetRow<FInventoryItemRow>("GetItem");
	if (InventoryItem && InventoryItem->Mesh.IsValid())
	{
		StaticMesh->SetStaticMesh(InventoryItem->Mesh.LoadSynchronous());
	}

}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::Interact()
{
	Destroy();
}

const FText& AItem::GetName() const
{
	return ItemInfo.ItemRow.GetRow<FInventoryItemRow>("GetItem")->ItemName;
}

