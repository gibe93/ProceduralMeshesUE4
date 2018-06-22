// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ProceduralMeshesGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProceduralMeshesGameModeBase() {}
// Cross Module References
	PROCEDURALMESHES_API UClass* Z_Construct_UClass_AProceduralMeshesGameModeBase_NoRegister();
	PROCEDURALMESHES_API UClass* Z_Construct_UClass_AProceduralMeshesGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ProceduralMeshes();
// End Cross Module References
	void AProceduralMeshesGameModeBase::StaticRegisterNativesAProceduralMeshesGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AProceduralMeshesGameModeBase_NoRegister()
	{
		return AProceduralMeshesGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AProceduralMeshesGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_ProceduralMeshes,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "ProceduralMeshesGameModeBase.h" },
				{ "ModuleRelativePath", "ProceduralMeshesGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AProceduralMeshesGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AProceduralMeshesGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProceduralMeshesGameModeBase, 868242431);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProceduralMeshesGameModeBase(Z_Construct_UClass_AProceduralMeshesGameModeBase, &AProceduralMeshesGameModeBase::StaticClass, TEXT("/Script/ProceduralMeshes"), TEXT("AProceduralMeshesGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProceduralMeshesGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
