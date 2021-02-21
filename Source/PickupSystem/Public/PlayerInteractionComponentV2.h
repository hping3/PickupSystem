// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "IncludePickSystem.h"
#include "UI_InteractMenuCPP.h"
#include "Components/SphereComponent.h"
#include "PlayerInteractionComponentV2.generated.h"


//Forward Declaration
class UInteractableActorComponent;
class UPlayerInteractionComponentV2;

/**
 * 
 */
UCLASS()
class PICKUPSYSTEM_API UPlayerInteractionComponentV2 : public USphereComponent
{
	GENERATED_BODY()


public:
	UPlayerInteractionComponentV2();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupSystem")
	TSubclassOf<class UUI_InteractMenuCPP> InteractMenu;
	

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

	UFUNCTION()
	void OnInteractionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                               UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                               const FHitResult& SweepResult);
	UFUNCTION()
	void OnInteractionEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	bool CollectInteractableActor(UInteractableActorComponent* InteractableActorComponent);


	void OnUse();

	void OnDrop();
	
protected:
	TArray<AActor*> ActorsInRange;
	TArray<AActor*> CollectedItems;
	
};
