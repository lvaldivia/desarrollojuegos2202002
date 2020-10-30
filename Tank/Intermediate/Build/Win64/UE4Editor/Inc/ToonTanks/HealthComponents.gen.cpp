// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToonTanks/Components/HealthComponents.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHealthComponents() {}
// Cross Module References
	TOONTANKS_API UClass* Z_Construct_UClass_UHealthComponents_NoRegister();
	TOONTANKS_API UClass* Z_Construct_UClass_UHealthComponents();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ToonTanks();
// End Cross Module References
	void UHealthComponents::StaticRegisterNativesUHealthComponents()
	{
	}
	UClass* Z_Construct_UClass_UHealthComponents_NoRegister()
	{
		return UHealthComponents::StaticClass();
	}
	struct Z_Construct_UClass_UHealthComponents_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHealthComponents_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ToonTanks,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHealthComponents_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/HealthComponents.h" },
		{ "ModuleRelativePath", "Components/HealthComponents.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHealthComponents_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHealthComponents>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UHealthComponents_Statics::ClassParams = {
		&UHealthComponents::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UHealthComponents_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UHealthComponents_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHealthComponents()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UHealthComponents_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHealthComponents, 1023153557);
	template<> TOONTANKS_API UClass* StaticClass<UHealthComponents>()
	{
		return UHealthComponents::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHealthComponents(Z_Construct_UClass_UHealthComponents, &UHealthComponents::StaticClass, TEXT("/Script/ToonTanks"), TEXT("UHealthComponents"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHealthComponents);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
