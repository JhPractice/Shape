# Snake 프로젝트 - Pre Project
콘솔상에서 렌더링 테스트를 하기 위해 만든 프로젝트
뱀이 입력을 받아 이동을 한다.
* 콘솔 더블 버퍼링 구현
* Processor와 Renderer의 기본구조 구현

# Circle 프로젝트
본프로젝트로 콘솔 상에서 기본적인 도형그리기와 회전 게임 엔진의 기본 구조를 구현하였다.
두개의 동그라미와 한개의 십자가가 콘솔상에서 회전을 한다.
* Processor - 주요 처리부, 데이터의 변형을 담당한다.
* Renderer - Shape(렌더링데이터)를 렌더링한다.
* ResourceMgr - 원본 데이터를 로딩 및 메모리 상의 생성을 담당한다.
* DataSequenceMgr - 렌더링될 변형된 데이터를 보관한다.
* Shape - 렌더링 되는 데이터.
* GameObject - Entity로 각 속성들을 보관하며 엔진의 사용자가 제어하게 될 개체다.




*Lectured By 3DMPEngines*