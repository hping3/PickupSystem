// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class PickupSystem : ModuleRules
{
	public PickupSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.AddRange(
			new string[] 
			{
				Path.Combine(ModuleDirectory, "Public")
			}
		);
		
		PublicIncludePaths.AddRange(
			new string[]
			{
				"PickupSystem/Public",
			
			}
		);

		PrivateIncludePaths.AddRange(
			new string[] 
			{
				"PickupSystem/Private",
		    }		
		);

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","UMG", "Slate", "SlateCore" });
	}
}
