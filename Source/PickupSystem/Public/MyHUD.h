// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UI_InteractMenuCPP.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class PICKUPSYSTEM_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	public:


	AMyHUD() = default;
	virtual void Tick(float DeltaSeconds) override;
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> UIclass;

	private:
	UUI_InteractMenuCPP* UIInstance;
};
