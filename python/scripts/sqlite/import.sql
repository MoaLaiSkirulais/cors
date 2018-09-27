drop table IF EXISTS edata;
.mode csv
.import data.csv edata

drop table IF EXISTS euser;
.mode csv
.import users.csv euser

drop table IF EXISTS evoter;
.mode csv
.import voters.csv evoter

.header on
.mode column

-- clean
-- delete from tblelection;
-- delete from tblparty;
-- delete from tblcandidate;
-- delete from tblstate;
-- delete from tblrole;
-- delete from tbllist;
-- delete from tbllistcandidate;
-- delete from tbluser;

-- insert election
insert into tblelection(tbStatus, tbScope, name)
select distinct 'active', 'Nacional', 'Elecciones Legislativas Nacionales Argentina' from edata;

-- normaliza distritos
insert into tblstate(code, name)
select distinct codigo_distrito, distrito from edata;

-- insert tbllocalelection
insert into tbllocalelection(electionId, stateId, tbStatus, tbScope)
select e.electionId, s.stateId, 'A', 'state' 
from tblelection e
	inner join tblstate s;

-- normaliza cargos
insert into tblrole(name)
select distinct nombre_cargo from edata;

-- normaliza partidos
insert into tblparty(code, name)
select distinct codigo_ap, agrupacion_politica from edata;

-- normaliza candidatos
insert into tblcandidate(name, doc, dob)
select distinct nombre, documento, fecha_nac from edata;

-- verificacion
-- select * from tblelection limit 10;
-- select * from tblparty limit 10;
-- select * from tbllist limit 10;
-- select * from tblcandidate limit 10;
-- select * from tblstate limit 10;
-- select * from tblrole limit 10;

-- limit 10;

-- agrego columnas
ALTER TABLE edata ADD COLUMN partyId integer;
ALTER TABLE edata ADD COLUMN stateId integer;
ALTER TABLE edata ADD COLUMN candidateId integer;

update edata 
set partyId=(select p.partyId from tblparty p where p.code=edata.codigo_ap);

update edata 
set stateId=(select s.stateId from tblstate s where s.code=edata.codigo_distrito);

update edata 
set candidateId=(select c.candidateId from tblcandidate c where c.doc=edata.documento);

-- prepara listas
-- insert into tbllist(partyId, stateId)
-- select distinct	e.partyId, e.stateId from edata e;

insert into tbllist(partyId, localElectionId)
select distinct	e.partyId, l.localElectionId 
from edata e
	inner join tbllocalelection l
		on e.stateId = l.stateId;

-- prepara candidatos
insert into tbllistcandidate(listid, candidateid)
select l.listid, e.candidateid 
from edata e 
       
	inner join tbllist l
		on l.partyId=e.partyId
      
      inner join tbllocalelection lo
			on lo.stateId=e.stateId
				and lo.localelectionId = l.localelectionId;
		
-- insert users
insert into tbluser(email, username, password, tbStatus, stateId)
select e.email, e.username, e.password, e.tbStatus, e.stateId
from euser e;	

-- insert voters
insert into tblvoter(username, tbSource)
select e.username, e.tbSource
from evoter e;	

-- insert results
insert into tblresult(localElectionId, listId, total)
select l.localELectionId, l.listId, 0 from tbllist l;

-- chequeos
-- select 'edata' as tablename, count(*) from edata;
-- select 'euser' as tablename, count(*) from euser;
-- select 'evoter' as tablename, count(*) from evoter;

select name as 'name____________', seq from sqlite_sequence;




