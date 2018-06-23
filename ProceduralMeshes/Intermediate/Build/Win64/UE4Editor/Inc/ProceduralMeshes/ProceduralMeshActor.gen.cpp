// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ProceduralMeshActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProceduralMeshActor() {}
// Cross Module References
	PROCEDURALMESHES_API UClass* Z_Construct_UClass_AProceduralMeshActor_NoRegister();
	PROCEDURALMESHES_API UClass* Z_Construct_UClass_AProceduralMeshActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProceduralMeshes();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	void AProceduralMeshActor::StaticRegisterNativesAProceduralMeshActor()
	{
	}
	UClass* Z_Construct_UClass_AProceduralMeshActor_NoRegister()
	{
		return AProceduralMeshActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AProceduralMeshActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_ProceduralMeshes,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "ProceduralMeshActor.h" },
				{ "ModuleRelativePath", "ProceduralMeshActor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelectedVertexEffect_MetaData[] = {
				{ "Category", "ProceduralMeshActor" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "ProceduralMeshActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SelectedVertexEffect = { UE4CodeGen_Private::EPropertyClass::Object, "SelectedVertexEffect", RF_Public|RF_Transient|RF_MarkAsNative, 0x002008000008001d, 1, nullptr, STRUCT_OFFSET(AProceduralMeshActor, SelectedVertexEffect), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(NewProp_SelectedVertexEffect_MetaData, ARRAY_COUNT(NewProp_SelectedVertexEffect_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProceduralMesh_MetaData[] = {
				{ "Category", "ProceduralMeshActor" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "ProceduralMeshActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProceduralMesh = { UE4CodeGen_Private::EPropertyClass::Object, "ProceduralMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000a000d, 1, nullptr, STRUCT_OFFSET(AProceduralMeshActor, ProceduralMesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(NewProp_ProceduralMesh_MetaData, ARRAY_COUNT(NewProp_ProceduralMesh_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SelectedVertexEffect,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProceduralMesh,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AProceduralMeshActor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AProceduralMeshActor::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProceduralMeshActor, 66996915);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProceduralMeshActor(Z_Construct_UClass_AProceduralMeshActor, &AProceduralMeshActor::StaticClass, TEXT("/Script/ProceduralMeshes"), TEXT("AProceduralMeshActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProceduralMeshActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
