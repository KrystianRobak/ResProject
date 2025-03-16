// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RES : ModuleRules
{
	public RES(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
