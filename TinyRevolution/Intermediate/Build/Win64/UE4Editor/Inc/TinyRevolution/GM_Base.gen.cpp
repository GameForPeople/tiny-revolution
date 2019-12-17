// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TinyRevolution/GM_Base.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGM_Base() {}
// Cross Module References
	TINYREVOLUTION_API UClass* Z_Construct_UClass_AGM_Base_NoRegister();
	TINYREVOLUTION_API UClass* Z_Construct_UClass_AGM_Base();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TinyRevolution();
// End Cross Module References
	void AGM_Base::StaticRegisterNativesAGM_Base()
	{
	}
	UClass* Z_Construct_UClass_AGM_Base_NoRegister()
	{
		return AGM_Base::StaticClass();
	}
	struct Z_Construct_UClass_AGM_Base_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGM_Base_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TinyRevolution,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGM_Base_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GM_Base.h" },
		{ "ModuleRelativePath", "GM_Base.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGM_Base_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGM_Base>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGM_Base_Statics::ClassParams = {
		&AGM_Base::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_AGM_Base_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGM_Base_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGM_Base()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGM_Base_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGM_Base, 482846656);
	template<> TINYREVOLUTION_API UClass* StaticClass<AGM_Base>()
	{
		return AGM_Base::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGM_Base(Z_Construct_UClass_AGM_Base, &AGM_Base::StaticClass, TEXT("/Script/TinyRevolution"), TEXT("AGM_Base"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGM_Base);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
