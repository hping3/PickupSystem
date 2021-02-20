// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponentV2.h"

#include "InteractableActorComponent.h"

UPlayerInteractionComponentV2::UPlayerInteractionComponentV2()
{
	InitSphereRadius(400.0f);
	SetGenerateOverlapEvents(true);
	UPrimitiveComponent::SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	bHiddenInGame = false;
}

void UPlayerInteractionComponentV2::BeginPlay()
{

	Super::BeginPlay();
	OnComponentBeginOverlap.AddDynamic(this, &UPlayerInteractionComponentV2::OnInteractionBeginOverlap);
	
}

void UPlayerInteractionComponentV2::OnInteractionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("debuga z OnInteractionOverlapBegin") );

	/* ignoring collision with owing Actor */
	if(OtherActor ==nullptr || OtherActor== this->GetOwner())
	{
		return;	
	}
	UInteractableActorComponent* comp = OtherActor->FindComponentByClass<UInteractableActorComponent>();

	/* can't find InteractableActorComponent or we can't interact*/
	if(comp == nullptr || !comp->CanInteract(GetOwner(),this))
	{
		return;
	}

	//@todo pewnie trzeba dodac, wskazniki albo move sematnic
	FInteractionOption Options = comp->GetInteractionOptions();

	
	comp->Interact(GetOwner(),this,Options.DefaultOption);

	//@todo dlaczego nie mogę przekazac enum od razu w  parametrze tylko musze robić Type = ...
	//comp->Interact(InteractionType::READ);
	

	
	
	
}

bool UPlayerInteractionComponentV2::CollectInteractableActor(UInteractableActorComponent* InteractableActorComponent)
{
	//@todo dodac obbsluge inventory, czy jest miejsce itd
	return true;
}
