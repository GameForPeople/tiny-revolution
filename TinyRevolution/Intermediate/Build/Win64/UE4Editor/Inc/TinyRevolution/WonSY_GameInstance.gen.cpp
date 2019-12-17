// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TinyRevolution/WonSY_GameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWonSY_GameInstance() {}
// Cross Module References
	TINYREVOLUTION_API UClass* Z_Construct_UClass_UWonSY_GameInstance_NoRegister();
	TINYREVOLUTION_API UClass* Z_Construct_UClass_UWonSY_GameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_TinyRevolution();
	TINYREVOLUTION_API UFunction* Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork();
	TINYREVOLUTION_API UFunction* Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork();
// End Cross Module References
	void UWonSY_GameInstance::StaticRegisterNativesUWonSY_GameInstance()
	{
		UClass* Class = UWonSY_GameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EndNetwork", &UWonSY_GameInstance::execEndNetwork },
			{ "StartNetwork", &UWonSY_GameInstance::execStartNetwork },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork_Statics::Function_MetaDataParams[] = {
		{ "Category", "WONSY_NETWORK" },
		{ "ModuleRelativePath", "WonSY_GameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWonSY_GameInstance, nullptr, "EndNetwork", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics
	{
		struct WonSY_GameInstance_eventStartNetwork_Parms
		{
			bool isUsePublicIP;
		};
		static void NewProp_isUsePublicIP_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isUsePublicIP;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::NewProp_isUsePublicIP_SetBit(void* Obj)
	{
		((WonSY_GameInstance_eventStartNetwork_Parms*)Obj)->isUsePublicIP = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::NewProp_isUsePublicIP = { "isUsePublicIP", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WonSY_GameInstance_eventStartNetwork_Parms), &Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::NewProp_isUsePublicIP_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::NewProp_isUsePublicIP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::Function_MetaDataParams[] = {
		{ "Category", "WONSY_NETWORK" },
		{ "ModuleRelativePath", "WonSY_GameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWonSY_GameInstance, nullptr, "StartNetwork", nullptr, nullptr, sizeof(WonSY_GameInstance_eventStartNetwork_Parms), Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWonSY_GameInstance_NoRegister()
	{
		return UWonSY_GameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UWonSY_GameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWonSY_GameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_TinyRevolution,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UWonSY_GameInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UWonSY_GameInstance_EndNetwork, "EndNetwork" }, // 2606201822
		{ &Z_Construct_UFunction_UWonSY_GameInstance_StartNetwork, "StartNetwork" }, // 742249360
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWonSY_GameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "WonSY_GameInstance.h" },
		{ "ModuleRelativePath", "WonSY_GameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWonSY_GameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWonSY_GameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UWonSY_GameInstance_Statics::ClassParams = {
		&UWonSY_GameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UWonSY_GameInstance_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UWonSY_GameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UWonSY_GameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UWonSY_GameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWonSY_GameInstance, 3209263310);
	template<> TINYREVOLUTION_API UClass* StaticClass<UWonSY_GameInstance>()
	{
		return UWonSY_GameInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWonSY_GameInstance(Z_Construct_UClass_UWonSY_GameInstance, &UWonSY_GameInstance::StaticClass, TEXT("/Script/TinyRevolution"), TEXT("UWonSY_GameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWonSY_GameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
