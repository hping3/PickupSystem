// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IncludePickSystem.h"
#include "Components/ActorComponent.h"
#include "InteractableActorComponent.generated.h"



UENUM(BlueprintType)
enum class InteractionType : uint8 {
	COLLECT = 0			UMETA(DisplayName = "COLLECT"),
    INSTA_COLLECT = 1	UMETA(DisplayName = "INSTA_COLLECT"),
    LISTEN = 2			UMETA(DisplayName = "LISTEN"),
	READ = 3			UMETA(DisplayName = "READ"),
    USE = 4				UMETA(DisplayName = "USE") 
};

USTRUCT(BlueprintType)
struct FInteractionOption
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupSystem")
	InteractionType DefaultOption;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupSystem")
	TArray<InteractionType> Options;
};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PICKUPSYSTEM_API UInteractableActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableActorComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupSystem")
	FInteractionOption Options;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual FInteractionOption GetInteractionOptions();
	virtual void Interact(AActor* Actor, UPlayerInteractionComponentV2* PlayerComponent,InteractionType& Type) ;
	virtual bool CanInteract(AActor* Actor, UPlayerInteractionComponentV2* PlayerComponent);
	
};
