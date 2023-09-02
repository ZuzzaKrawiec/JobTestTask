// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ZuzannaKrawiec : ModuleRules
{
	public ZuzannaKrawiec(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"NavigationSystem", 
			"AIModule", 
			"Niagara", 
			"EnhancedInput",
			"UMG",
			"SlateCore"
		});

        PublicIncludePaths.AddRange(new string[]
        {
            ModuleDirectory
        });
    }
}
