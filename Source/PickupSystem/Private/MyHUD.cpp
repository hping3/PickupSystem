// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

void AMyHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();
	if(UIclass)
	{
		UIInstance = CreateWidget<UUI_InteractMenuCPP>(GetWorld(),UIclass);
		if(UIInstance)
		{
			UIInstance->AddToViewport();
		}
		
	}
}
