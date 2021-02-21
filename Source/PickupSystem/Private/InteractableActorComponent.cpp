// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActorComponent.h"

#include "Kismet/GameplayStatics.h"

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



FInteractionOption UInteractableActorComponent::GetInteractionOptions()
{
	return Options;
}

bool UInteractableActorComponent::Interact(AActor* Actor, UPlayerInteractionComponentV2* PlayerComponent,
                                           InteractionType& Type) 
{
	UE_LOG(LogTemp, Warning, TEXT("debuga z Interact") );
	AActor* Owner = GetOwner();
	if(Owner ==nullptr)
	{
		return false;
	}
	
	if(Type == InteractionType::INSTA_COLLECT)
	{
		if(PlayerComponent->CollectInteractableActor(this))
		{
			// Owner->bHiddenEdLevel =true;
			//Owner->Destroy();
			return  true;
		}
	}

	if(Type == InteractionType::COLLECT)
	{
		if(PlayerComponent->CollectInteractableActor(this))
		{
			return true;
		}
	}
	
	if(Type == InteractionType::LISTEN)
	{
		UGameplayStatics::PlaySoundAtLocation(this,ListenSound,GetOwner()->GetActorLocation());
		return true;
	}

	return  false;
}


bool UInteractableActorComponent::CanInteract(AActor* Actor, UPlayerInteractionComponentV2* PlayerComponent)
{
	return true;
}


