// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableActorComponent.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"



#include "UI_InteractMenuCPP.generated.h"

//forward declaration nie dizala w przypadku parametru dla struktury w ufunction
// struct FInteractionOption;
/**
 * 
 */
UCLASS()
class PICKUPSYSTEM_API UUI_InteractMenuCPP : public UUserWidget
{
	GENERATED_BODY()
	public:


	UUI_InteractMenuCPP(const FObjectInitializer& MovieSceneBlends);
		

protected:
	virtual void NativeConstruct() override;
public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowMenuWithComp(UInteractableActorComponent* Component);

	UFUNCTION(BlueprintImplementableEvent)
    void OnShowTestMenu();

	//UFUNCTION(BlueprintImplementableEvent)
	//void ShowMenuWithStruct(FInteractionOption tesowyparams);

	// UFUNCTION(BlueprintImplementableEvent)
    // void ShowMenuWithStruct(UMyPassClass* tesowyparams);
    
};
