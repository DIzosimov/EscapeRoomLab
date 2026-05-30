// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyRing.h"

// Sets default values
AKeyRing::AKeyRing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void AKeyRing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKeyRing::AddKey(FName KeyId)
{
    if (CollectedKeys.Contains(KeyId)) return;

    CollectedKeys.Add(KeyId);
    KeyUsageCount.Add(KeyId, 0);

    const FString Msg = FString::Printf(TEXT("Added key: %s"), *KeyId.ToString());
    UE_LOG(LogTemp, Log, TEXT("%s"), *Msg);
}

bool AKeyRing::HasKey(FName KeyId) const
{
    return CollectedKeys.Contains(KeyId);
}

void AKeyRing::UseKey(FName KeyId)
{
    if (int32* Count = KeyUsageCount.Find(KeyId))
    {
        (*Count)++;
    }
}

FText AKeyRing::GetKeyCountDisplay() const
{
    return FText::FromString(FString::Printf(TEXT("Keys: %d"), CollectedKeys.Num()));
}

void AKeyRing::BeginPlay()
{
    Super::BeginPlay();
    AddKey(TEXT("BrassKey"));
    AddKey(TEXT("SilverKey"));
    UE_LOG(LogTemp, Log, TEXT("%s"), *GetKeyCountDisplay().ToString());
}