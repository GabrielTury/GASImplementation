// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASTraining : ModuleRules
{
	public GASTraining(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"GASTraining",
			"GASTraining/Variant_Platforming",
			"GASTraining/Variant_Combat",
			"GASTraining/Variant_Combat/AI",
			"GASTraining/Variant_SideScrolling",
			"GASTraining/Variant_SideScrolling/Gameplay",
			"GASTraining/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
