// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "IncludePickSystem.h"
#include "Components/SphereComponent.h"
#include "PlayerInteractionComponentV2.generated.h"


//Forward Declaration
//class UInteractableActorComponent;
//class UPlayerInteractionComponentV2;

/**
 * 
 */
UCLASS()
class PICKUPSYSTEM_API UPlayerInteractionComponentV2 : public USphereComponent
{
	GENERATED_BODY()


public:
	UPlayerInteractionComponentV2();

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnInteractionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                               UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                               const FHitResult& SweepResult);
	
	bool CollectInteractableActor(UInteractableActorComponent* InteractableActorComponent);
};
