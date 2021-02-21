// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponentV2.h"

#include "InteractableActorComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerInput.h"

UPlayerInteractionComponentV2::UPlayerInteractionComponentV2()
{
	InitSphereRadius(400.0f);
	SetGenerateOverlapEvents(true);
	UPrimitiveComponent::SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	bHiddenInGame = false;

	//@todo właczac tick tlyko w edytorze
	if(GEngine->IsEditor())
	{
		PrimaryComponentTick.bCanEverTick = true;
		PrimaryComponentTick.bStartWithTickEnabled = true;
	}
	

	
}

void UPlayerInteractionComponentV2::BeginPlay()
{

	Super::BeginPlay();
	OnComponentBeginOverlap.AddDynamic(this, &UPlayerInteractionComponentV2::OnInteractionBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this,&UPlayerInteractionComponentV2::OnInteractionEndOverlap);

		

	AActor* Owner = Cast<AActor>(GetOwner());
	if (Owner)
	{
		Owner->InputComponent->BindAction("Use",EInputEvent::IE_Pressed,this,&UPlayerInteractionComponentV2::OnUse);
		Owner->InputComponent->BindAction("Drop",EInputEvent::IE_Pressed,this,&UPlayerInteractionComponentV2::OnDrop);
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("Object not inherid by ACharacter. User input actions don't work. ") );
	}


	
}

void UPlayerInteractionComponentV2::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	FString DebugMSG = FString::Printf(TEXT("Collected Items: %d"),CollectedItems.Num());
	GEngine->AddOnScreenDebugMessage(1,0.0f,FColor::Blue,DebugMSG);
	FString DebugMSG2 = FString::Printf(TEXT("In range Items: %d"),ActorsInRange.Num());
	GEngine->AddOnScreenDebugMessage(2,0.0f,FColor::Green,DebugMSG2);
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

	
	FInteractionOption Options = comp->GetInteractionOptions();

	
	if(Options.DefaultOption == InteractionType::INSTA_COLLECT)
	{
		//jezeli udalo sie podniesc konczymy metode zeby nie dodac do actors in range
		if(comp->Interact(GetOwner(),this,Options.DefaultOption))
		{
			return;
		}
	}
	
	ActorsInRange.Add(OtherActor);
	
	
	
}

void UPlayerInteractionComponentV2::OnInteractionEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	//@todo czy to moze poleciec nullptr? Np aktor zostanie ubity w innym watku zanim wykona sie ponizsza linja kodu ?
	ActorsInRange.Remove(OtherActor);
}


bool UPlayerInteractionComponentV2::CollectInteractableActor(UInteractableActorComponent* InteractableActorComponent)
{
	//@todo dodac obbsluge inventory, czy jest miejsce itd
	//testowo jezeli mamy juz 5 przedmiotow to nie mozna podniesc nastepnego
	if(CollectedItems.Num()>=5)
	{
		return  false;
	}
	
	CollectedItems.Add(InteractableActorComponent->GetOwner());
	InteractableActorComponent->GetOwner()->SetActorHiddenInGame(true);
	return true;
}

void UPlayerInteractionComponentV2::OnUse()
{
	UE_LOG(LogTemp, Warning, TEXT("debuga z OnUSE") );
	//@todo sprawdzic czy nie jest nullem
	if( ActorsInRange.Num()>0)
	{
		//@todo zdublowany kod z eventem OnInteractionBeginOverlap - potrzebny refaktor
		UInteractableActorComponent* comp = ActorsInRange.Last()->FindComponentByClass<UInteractableActorComponent>();
		/* can't find InteractableActorComponent or we can't interact*/
		if(comp == nullptr || !comp->CanInteract(GetOwner(),this))
		{
			return;
		}

		FInteractionOption OptionsInComp = comp->GetInteractionOptions();

		if(OptionsInComp.AvailableOptions.Num()==1)
		{
			comp->Interact(GetOwner(),this,OptionsInComp.DefaultOption);
		}else
		{
			//@todo show popupmenu 	
		}

		
	}
}

void UPlayerInteractionComponentV2::OnDrop()
{
	//simple drop system, last item remove
	if(CollectedItems.Num()>0)
	{
		CollectedItems.Remove(CollectedItems.Last());
	}
}
