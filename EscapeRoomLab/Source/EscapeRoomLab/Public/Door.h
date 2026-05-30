// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class ESCAPEROOMLAB_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Root pivot. Rotate this to swing the door. MeshComp hangs off it
	// with a Y offset so the actor origin sits at the hinge edge.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	bool bIsLocked = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door",
		meta = (ClampMin = "0.0", ClampMax = "180.0"))
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	float OpenDuration = 1.5f;

	UPROPERTY(EditAnywhere, Category = "Door")
	FName RequiredKeyId;

	UPROPERTY(VisibleAnywhere, Category = "Door")
	TArray<FName> KeysHeld;

	UFUNCTION(BlueprintCallable, Category = "Door")
	bool TryOpen();

	UFUNCTION(BlueprintImplementableEvent, Category = "Door")
	void OnDoorOpened();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
