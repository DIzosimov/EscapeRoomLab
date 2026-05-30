// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h" 
#include "PickupBase.generated.h"

UCLASS()
class ESCAPEROOMLAB_API APickupBase : public AActor
{
	GENERATED_BODY()
	

public:
	// Sets default values for this actor's properties
	APickupBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
	FName PickupId = TEXT("Unnamed");

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	bool bIsCollected = false;

	UPROPERTY(EditDefaultsOnly, Category = "Pickup|Respawn",
          meta = (ClampMin = "0.0", ClampMax = "60.0"))
	float RespawnDelay = 5.0f;

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY()
	TObjectPtr<AActor> LastCollector;
	AActor* UnsafeCollector = nullptr;

	UFUNCTION(BlueprintCallable)
	FString GetLastCollectorName() const;

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void Collect(AActor* Collector);

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
	void OnPickupCollected();

	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsAvailable() const { return !bIsCollected; }

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

