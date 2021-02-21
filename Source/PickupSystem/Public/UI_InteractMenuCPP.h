// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InteractableActorComponent.h"
#include "Blueprint/UserWidget.h"
#include "UI_InteractMenuCPP.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPSYSTEM_API UUI_InteractMenuCPP : public UUserWidget
{
	GENERATED_BODY()
	public:
//@Todo jak zadeklarować metode tak aby niebyla potrzebna implementacja w c++, to ma byc metoda w caloscinapisana w BP
	UFUNCTION(BlueprintNativeEvent)
	void ShowMenu(FInteractionOption Options);

	//FInteractionOption Options)
};
