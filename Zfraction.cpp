
bool Zfraction::estEgal(Zfraction const &objet2) const{
    if(this->m_numerateur == objet2.m_numerateur && this->m_denominateur == objet2.m_denominateur){return true;}
    else{return false;}
}