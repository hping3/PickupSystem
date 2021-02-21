// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IncludePickSystem.h"
#include "Components/ActorComponent.h"
#include "InteractableActorComponent.generated.h"

//Forward Declaration
class UInteractableActorComponent;
class UPlayerInteractionComponentV2;


UENUM(BlueprintType)
enum class InteractionType : uint8 {
	NONE = 0			UMETA(DisplayName = "NONE"),
	COLLECT = 1			UMETA(DisplayName = "COLLECT"),
    INSTA_COLLECT = 2	UMETA(DisplayName = "INSTA_COLLECT"),
    LISTEN = 3			UMETA(DisplayName = "LISTEN"),
	READ = 4			UMETA(DisplayName = "READ"),
    USE = 5				UMETA(DisplayName = "USE") 
};

USTRUCT(BlueprintType)
struct FInteractionOption
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupSystem")
	InteractionType DefaultOption;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupSystem")
	TArray<InteractionType> AvailableOptions;
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupSystem")
	USoundBase* ListenSound;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	


	virtual FInteractionOption GetInteractionOptions();
	virtual bool Interact(AActor* Actor, UPlayerInteractionComponentV2* PlayerComponent, InteractionType& Type) ;
	virtual bool CanInteract(AActor* Actor, UPlayerInteractionComponentV2* PlayerComponent);
	
};
