// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADoor::ADoor()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
    Super::BeginPlay();
    KeysHeld.Add(TEXT("BrassKey"));
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

bool ADoor::TryOpen()
{
    // Per spec: open if no key required, or if the required key is held.
    const bool bNoKeyRequired = RequiredKeyId.IsNone();
    const bool bHasRequiredKey = KeysHeld.Contains(RequiredKeyId);

    if (!bNoKeyRequired && !bHasRequiredKey)
    {
        UE_LOG(LogTemp, Log, TEXT("Door locked: missing key %s"), *RequiredKeyId.ToString());
        return false;
    }

    UE_LOG(LogTemp, Log, TEXT("Door opened"));
    OnDoorOpened();
    return true;
}
