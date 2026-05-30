// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyRing.generated.h"

UCLASS()
class ESCAPEROOMLAB_API AKeyRing : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeyRing();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	TArray<FName> CollectedKeys;

	UPROPERTY()
	TMap<FName, int32> KeyUsageCount;

	UFUNCTION(BlueprintCallable)
	void AddKey(FName KeyId);

	UFUNCTION(BlueprintCallable)
	bool HasKey(FName KeyId) const;

	UFUNCTION(BlueprintCallable)
	void UseKey(FName KeyId);

	UFUNCTION(BlueprintPure)
	FText GetKeyCountDisplay() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
