// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Rupee.h"
#include "Data/RuppeeData.h"
#include "Components/SphereComponent.h"

// Sets default values
ARupee::ARupee() : RupeeValue(0), MoneyType(EMoneyType::BLUE)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RupeeMesh"));
	MeshComponent->SetupAttachment(RootComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->InitSphereRadius(25.0f);
	SphereComponent->SetupAttachment(MeshComponent);
}

// Called when the game starts or when spawned
void ARupee::BeginPlay()
{
	Super::BeginPlay();

}

void ARupee::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);


	// Load the data table
	FString MoneyTablePath(TEXT("/Script/Engine.DataTable'/Game/DataTables/MoneyDataTable.MoneyDataTable'"));
	auto DataTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *MoneyTablePath));
	if (DataTable)
	{
		FMoneyData* RowData = nullptr;
		switch (MoneyType)
		{
		case EMoneyType::BLUE:
			RowData = DataTable->FindRow<FMoneyData>(FName("Blue"), FString());
			break;
		case EMoneyType::GOLD:
			RowData = DataTable->FindRow<FMoneyData>(FName("Gold"), FString());
			break;
		case EMoneyType::GREEN:
			RowData = DataTable->FindRow<FMoneyData>(FName("Green"), FString());
			break;
		case EMoneyType::RED:
			RowData = DataTable->FindRow<FMoneyData>(FName("Red"), FString());
			break;
		case EMoneyType::SILVER:
			RowData = DataTable->FindRow<FMoneyData>(FName("Silver"), FString());
			break;
		case EMoneyType::MAX_VALUE:
		default:
			break;
		}

		if (RowData)
		{
			// Set the mesh material
			if (MeshComponent)
			{
				MeshComponent->SetStaticMesh(RowData->RupeeMesh.LoadSynchronous());
			}
			RupeeValue = RowData->Value;
			RupeeIcon = RowData->RupeeIcon;
		}
	}

}

// Called every frame
void ARupee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

