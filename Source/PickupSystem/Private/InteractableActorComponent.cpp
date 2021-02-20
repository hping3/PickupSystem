// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActorComponent.h"

// Sets default values for this component's properties
UInteractableActorComponent::UInteractableActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractableActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractableActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FInteractionOption UInteractableActorComponent::GetInteractionOptions()
{
	return Options;
}

void UInteractableActorComponent::Interact(AActor* Actor, UPlayerInteractionComponentV2* PlayerComponent,
	InteractionType& Type) 
{
	UE_LOG(LogTemp, Warning, TEXT("debuga z Interact") );
	if(Type == InteractionType::COLLECT ||Type == InteractionType::INSTA_COLLECT)
	{
		if(PlayerComponent->CollectInteractableActor(this))
		{
			AActor* Owner = GetOwner();
			if(Owner ==nullptr)
			{
				return;;
			}
			Owner->bHiddenEdLevel =true;
		}
		
	}
}


bool UInteractableActorComponent::CanInteract(AActor* Actor, UPlayerInteractionComponentV2* PlayerComponent)
{
	return true;
}


