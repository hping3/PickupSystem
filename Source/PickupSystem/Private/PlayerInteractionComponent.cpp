// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponent.h"

#include "ComponentUtils.h"

// Sets default values for this component's properties
UPlayerInteractionComponent::UPlayerInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	PlayerInteractionComponent = CreateDefaultSubobject<UPlayerInteractionComponentV2>(TEXT("PlayerInteractionComponent"));
	

	//LookingItemsArea = CreateDefaultSubobject<USphereComponent>(TEXT("LookingItemsArea"));

	/*
	AActor* asdada = GetOwner();
	AActor* bddada = LookingItemsArea->GetOwner();
	bool isOwnerSelected = IsOwnerSelected();
	
	USceneComponent* scnka = asdada->GetRootComponent();
	
	LookingItemsArea->SetupAttachment(scnka);
	*/

	// ...
}


// Called when the game starts
void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

