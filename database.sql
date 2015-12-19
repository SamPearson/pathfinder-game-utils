-- MySQL dump 10.14  Distrib 5.5.46-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: pathf_DB
-- ------------------------------------------------------
-- Server version	5.5.46-MariaDB-1ubuntu0.14.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `monsters`
--

DROP TABLE IF EXISTS `monsters`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `monsters` (
  `name` varchar(20) DEFAULT NULL,
  `CR` int(11) DEFAULT NULL,
  `XP` int(11) DEFAULT NULL,
  `perception_bonus` int(11) DEFAULT NULL,
  `environment` varchar(50) DEFAULT NULL,
  `groups` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `monsters`
--

LOCK TABLES `monsters` WRITE;
/*!40000 ALTER TABLE `monsters` DISABLE KEYS */;
INSERT INTO `monsters` VALUES ('Goblin',0,135,-1,'dungeon,forest,city','goblin'),('Goblin Boss',1,400,4,'dungeon,forest,city','goblin'),('Ghoul',1,400,7,'dungeon,forest,swamp,mountain,city','undead,skeleton,zombie,evil_adv'),('City Guard',1,200,1,'city',''),('Dire Rat',0,135,4,'dungeon,forest,city','goblin'),('Air Elemental',3,800,7,'desert,mountain,city','construct'),('Animated Statue',3,800,-5,'desert,dungeon,city','construct'),('Barghest',4,1200,11,'desert,dungeon,forest,mountain','goblin,werewolf'),('Black Dragon',8,4800,14,'swamp',''),('Boar',2,600,6,'forest',''),('Boggard',2,600,4,'swamp',''),('Doppleganger',3,800,9,'city,dungeon','goblin,orc'),('Earth Elemental',3,800,7,'desert,forest,mountain,swamp,city',''),('Evil Cleric',3,800,7,'city,desert','evil_adv'),('Evil Fighter',3,800,5,'city,desert','evil_adv'),('Evil Rogue',3,800,9,'city','evil_adv'),('Evil Wizard',3,800,4,'city,desert','evil_adv'),('Fire Elemental',3,800,7,'desert,mountain,city','construct'),('Gargoyle',4,1200,5,'city,desert,mountain,swamp',''),('Ghost',7,3200,18,'forest,desert,swamp','undead'),('Giant Centipede',0,200,4,'dungeon,forest,city','insect'),('Giant Spider',1,400,4,'dungeon,forest,swamp,mountain,desert,city','insect'),('Gray Ooze',4,1200,-5,'dungeon,swamp',''),('Green Hag',5,1600,15,'forest,swamp',''),('Hell Hound',3,800,7,'desert,mountain','evil_adv'),('Manticore',5,1600,9,'desert,mountain,swamp','evil_adv,goblin,orc'),('Medusa',7,3200,16,'swamp','serpent'),('Mimic',4,1200,14,'desert,dungeon,forest,mountain','hidden'),('Mummy',5,1600,16,'dungeon,mountain,swamp','undead'),('Orc',0,135,-1,'dungeon,forest,mountain,city','orc'),('Orc Boss',2,600,6,'mountain','orc'),('ReefClaw',1,400,6,'forest,swamp','hidden,insect'),('Salamander',6,2400,16,'desert,dungeon,mountain',''),('Serpentfolk',4,1200,10,'dungeon,forest','serpent'),('Skeletal Champion',2,600,6,'city,desert,dungeon,forest,mountain,swamp','undead,evil_adv'),('Skeleton',0,135,0,'dungeon,forest,swamp,mountain,desert,city','undead'),('Troglodyte',1,400,0,'dungeon,swamp',''),('Venomous Snake',1,400,9,'city,desert,forest,swamp','serpent,hidden'),('Water Elemental',3,800,5,'city,forest','hidden,construct'),('Werewolf',2,600,4,'city,dungeon,forest,mountain,swamp','werewolf'),('Will o the wisp',6,2400,17,'swamp',''),('Wolf',1,400,8,'forest,mountain,swamp',''),('Zombie',1,200,0,'city,desert,dungeon,forest,mountain,swamp',''),('Ogre',3,800,5,'dungeon,mountain','');
/*!40000 ALTER TABLE `monsters` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `traps`
--

DROP TABLE IF EXISTS `traps`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `traps` (
  `name` varchar(30) DEFAULT NULL,
  `CR` int(11) DEFAULT NULL,
  `XP` int(11) DEFAULT NULL,
  `perceptionDC` int(11) DEFAULT NULL,
  `disableDC` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `traps`
--

LOCK TABLES `traps` WRITE;
/*!40000 ALTER TABLE `traps` DISABLE KEYS */;
INSERT INTO `traps` VALUES ('Arrow Trap',1,400,20,20),('Pit Trap',1,400,20,20),('Poisoned Dart Trap',1,400,20,20),('Swinging Axe Trap',1,400,20,20),('Burning Hands Trap',2,600,26,26),('Fireball Trap',5,1600,28,28);
/*!40000 ALTER TABLE `traps` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-12-18 19:10:42
