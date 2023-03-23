
#include "MainScene.h"
#include "../GameObject/Player.h"
#include "../GameObject/Monster.h"
#include "../GameObject/BackObj.h"
#include "SceneResource.h"
#include "Camera.h"
#include "../Input.h"
#include "../Widget/CharacterHUD.h"
#include "../GameObject/TileMap.h"

CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

bool CMainScene::Init()
{
	CreateAnimationSequence();

	GetSceneResource()->LoadSound("BGM", "MainBGM", true, "MainBgm.mp3");
	GetSceneResource()->LoadSound("Effect", "TeemoSmile", false, "TeemoSmile.mp3");
	GetSceneResource()->LoadSound("Effect", "Gabung", false, "Demasia.mp3");
	GetSceneResource()->SoundPlay("MainBGM");

	GetSceneResource()->SetVolume(20);

	GetCamera()->SetResolution(1280.f, 720.f);
	GetCamera()->SetWorldResolution(1500.f, 1200.f);
	GetCamera()->SetTargetPivot(0.5f, 0.5f);

	CreateObject<CBackObj>("BackObj");

	CPlayer* Player = CreateObject<CPlayer>("Player");

	SetPlayer(Player);

	GetCamera()->SetTarget(Player);

	CMonster* Monster = CreateObject<CMonster>("Monster");
	//m_Monster = CreateObject<CMonster>("Monster");

	CTileMap* TileMap = CreateObject<CTileMap>("TileMap");

	TileMap->LoadFileName("MainMap.tmp", MAP_PATH);
	//TileMap->LoadFileName("MainMap1.tmp", MAP_PATH);


	CInput::GetInst()->AddBindFunction<CMainScene>("Cam1",
		Input_Type::Down, this, &CMainScene::Cam1Key, this);
	CInput::GetInst()->AddBindFunction<CMainScene>("Cam2",
		Input_Type::Down, this, &CMainScene::Cam2Key, this);

	CreateWidgetWindow<CCharacterHUD>("CharacterHUD");

	return true;
}

void CMainScene::CreateAnimationSequence()
{
	GetSceneResource()->CreateAnimationSequence("PlayerRightIdle",
		"PlayerRightIdle", TEXT("Player/Right/astand.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 6; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerRightIdle", 82.f * i, 0.f,
			82.f, 73.f);
	}

	GetSceneResource()->SetColorKey("PlayerRightIdle", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerRightWalk",
		"PlayerRightWalk", TEXT("Player/Right/awalk.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerRightWalk", 85.f * i, 0.f,
			85.f, 75.f);
	}

	GetSceneResource()->SetColorKey("PlayerRightWalk", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerRightAttack",
		"PlayerRightAttack", TEXT("Player/Right/aswing.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 3; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerRightAttack", 176.f * i, 0.f,
			176.f, 89.f);
	}

	GetSceneResource()->SetColorKey("PlayerRightAttack", 255, 0, 255);


	GetSceneResource()->CreateAnimationSequence("PlayerLeftIdle",
		"PlayerLeftIdle", TEXT("Player/Left/astand_left.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 6; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerLeftIdle", 82.f * i, 0.f,
			82.f, 73.f);
	}

	GetSceneResource()->SetColorKey("PlayerLeftIdle", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftWalk",
		"PlayerLeftWalk", TEXT("Player/Left/awalk_left.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerLeftWalk", 85.f * i, 0.f,
			85.f, 75.f);
	}

	GetSceneResource()->SetColorKey("PlayerLeftWalk", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftAttack",
		"PlayerLeftAttack", TEXT("Player/Left/aswing_left.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 3; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerLeftAttack", 176.f * i, 0.f,
			176.f, 89.f);
	}

	GetSceneResource()->SetColorKey("PlayerLeftAttack", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftProne",
		"PlayerLeftProne", TEXT("Player/Left/prone_left.bmp"), TEXTURE_PATH);

	GetSceneResource()->AddAnimationFrame("PlayerLeftProne", 0.f, 0.f,
		99.f, 54.f);

	GetSceneResource()->SetColorKey("PlayerLeftProne", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerRightProne",
		"PlayerRightProne", TEXT("Player/Right/prone.bmp"), TEXTURE_PATH);

	GetSceneResource()->AddAnimationFrame("PlayerRightProne", 0.f, 0.f,
		99.f, 54.f);

	GetSceneResource()->SetColorKey("PlayerRightProne", 255, 0, 255);



	GetSceneResource()->CreateAnimationSequence("LeftHitEffect",
		"LeftHitEffect", TEXT("Hit.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 6; ++i)
	{
		GetSceneResource()->AddAnimationFrame("LeftHitEffect", 178.f * i, 0.f,
			178.f, 164.f);
	}

	GetSceneResource()->SetColorKey("LeftHitEffect", 255, 0, 255);
}

void CMainScene::Cam1Key()
{
	GetCamera()->SetTarget(m_Player);
}

void CMainScene::Cam2Key()
{
	GetCamera()->SetTarget(m_Monster);
}
