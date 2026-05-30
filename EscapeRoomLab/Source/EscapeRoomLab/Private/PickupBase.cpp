// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupBase.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APickupBase::APickupBase()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("PickupBase BeginPlay: %s"), *GetName());
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupBase::Collect(AActor* Collector)
{
	if (bIsCollected) return;

	bIsCollected = true;
	LastCollector = Collector;
	UnsafeCollector = Collector;

	const FString CollectorName = Collector ? Collector->GetName() : TEXT("None");
	UE_LOG(LogTemp, Log, TEXT("Pickup %s collected by %s"),
		*PickupId.ToString(), *CollectorName);

	OnPickupCollected();
}

FString APickupBase::GetLastCollectorName() const
{
	return LastCollector ? LastCollector->GetName() : TEXT("None");
}

