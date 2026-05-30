// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EscapeRoomLab : ModuleRules
{
	public EscapeRoomLab(ReadOnlyTargetRules Target) : base(Target)
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
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EscapeRoomLab",
			"EscapeRoomLab/Variant_Platforming",
			"EscapeRoomLab/Variant_Platforming/Animation",
			"EscapeRoomLab/Variant_Combat",
			"EscapeRoomLab/Variant_Combat/AI",
			"EscapeRoomLab/Variant_Combat/Animation",
			"EscapeRoomLab/Variant_Combat/Gameplay",
			"EscapeRoomLab/Variant_Combat/Interfaces",
			"EscapeRoomLab/Variant_Combat/UI",
			"EscapeRoomLab/Variant_SideScrolling",
			"EscapeRoomLab/Variant_SideScrolling/AI",
			"EscapeRoomLab/Variant_SideScrolling/Gameplay",
			"EscapeRoomLab/Variant_SideScrolling/Interfaces",
			"EscapeRoomLab/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
