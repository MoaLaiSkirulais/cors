-- drop
drop table IF EXISTS tblelection;
drop table IF EXISTS tbllocalelection;
drop table IF EXISTS tblparty;
drop table IF EXISTS tblcandidate;
drop table IF EXISTS tblstate;
drop table IF EXISTS tblrole;
drop table IF EXISTS tbllist;
drop table IF EXISTS tbllistcandidate;
drop table IF EXISTS tblvote;
drop table IF EXISTS tbluser;
drop table IF EXISTS tblvoter;
drop table IF EXISTS tblresult;

-- tblelection
create table tblelection ( 

	electionId integer primary key autoincrement,
	creationDate timestamp default ((datetime('now','localtime'))),
	tbStatus varchar(1), 
	tbScope varchar(1), -- Nation | State | City
	name varchar(200) 
	
);

-- tbllocalelection
create table tbllocalelection ( 

	localElectionId integer primary key autoincrement,
	electionId integer, -- FK
	creationDate timestamp default ((datetime('now','localtime'))),
	stateId integer, -- FK
	tbStatus varchar(1), 
	tbScope varchar(1)  -- State | City
	
);

-- tblparty
create table tblparty(

	partyId integer primary key autoincrement,
	creationDate timestamp default ((datetime('now','localtime'))),
	code integer, 
	name varchar(200)
	
);

-- tbllist
create table tbllist(

	listId integer primary key autoincrement,
	localElectionId integer, -- FK
	partyId integer, -- FK	
	creationDate timestamp default ((datetime('now','localtime')))
	
);

-- tblcandidate
create table tblcandidate(

	candidateId integer primary key autoincrement, -- PK
	creationDate timestamp default ((datetime('now','localtime'))),
	name varchar(200), 
	doc varchar(200), -- dni
	dob varchar(200) -- nacimiento
	-- [order] integer 
	
);

-- tbllistcandidate
create table tbllistcandidate(

	listId integer, -- PK
	candidateId integer, -- PK
	primary key(listId, candidateId)

);

-- tblstate
create table tblstate(

	stateId integer primary key autoincrement, -- PK
	code integer, 
	name varchar(200) 
	
);

-- tblrole
create table tblrole(

	roleId integer primary key autoincrement, -- PK
	name varchar(200) 
	
);

-- tblvote
create table tblvote(

	voteId integer primary key autoincrement, -- PK
	creationDate timestamp default ((datetime('now','localtime'))),
	username varchar(100), -- PK
	tbSource varchar(100), -- facebook, local, anon
	electionId integer -- PK
	
);

-- tbluser
create table tbluser(

	userId integer primary key autoincrement, -- PK
	creationDate timestamp default ((datetime('now','localtime'))),
	email varchar(200),
	username varchar(200),
	password varchar(200), 
	stateId integer, -- FK
	tbStatus varchar(200) -- Active | Inactive
	
);

-- tblvoter
create table tblvoter(

	voterId integer primary key autoincrement, -- PK
	creationDate timestamp default ((datetime('now','localtime'))),
	username varchar(200),
	tbSource varchar(200) -- Facebook, localUser, Anon
	
);

-- tblresult
create table tblresult ( 

	resultId integer primary key autoincrement,
	localElectionId integer, -- FK
	listId integer, -- FK
	total integer	
);



