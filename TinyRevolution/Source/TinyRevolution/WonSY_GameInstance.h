// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// C++
#include <thread>
#include <atomic>

// Unreal
#include "Networking/Public/Networking.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../../Define.hh"

#include "WonSY_GameInstance.generated.h"
/**
 * 
 */

UCLASS()
class TINYREVOLUTION_API UWonSY_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "WONSY_NETWORK")
	void StartNetwork(bool isUsePublicIP);
	
	UFUNCTION(BlueprintCallable, Category = "WONSY_NETWORK")
	void EndNetwork();

	void NetworkFunction();

	void ProcessPacket();

private:
	FSocket* socket;

	//TArray<uint8> recvBuffer;
	uint8 recvBuffer[DEFINE::RECV_BUFFER_MAX_SIZE];
	uint8 loadedBuffer[DEFINE::PACKET_MAX_SIZE];
	uint8 loadedSize = 0;

	std::thread networkThread;
	std::atomic<bool> isNetworkEnd = true;

	TQueue<TArray<uint8>, EQueueMode::Mpsc> sendTaskQueue;
};
