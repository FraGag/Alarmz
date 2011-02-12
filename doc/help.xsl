<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0"
                exclude-result-prefixes="html x"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:html="http://www.w3.org/1999/xhtml"
                xmlns:x="urn:x">
    <xsl:output method="html" indent="yes" encoding="utf-8" doctype-public="-//W3C//DTD HTML 4.01//EN" doctype-system="http://www.w3.org/TR/html4/strict.dtd"/>
    <xsl:param name="language" select="'en-US'"/>
    <xsl:variable name="strings" select="document(concat(translate($language, '-', '_'), '/strings.xml'))/x:strings"/>
    <xsl:param name="extension" select="'.xml'"/>
    <xsl:param name="sharedpath" select="''"/>

    <xsl:template match="@* | node()">
        <xsl:copy>
            <xsl:apply-templates select="@* | node()"/>
        </xsl:copy>
    </xsl:template>

    <xsl:template match="processing-instruction()"></xsl:template>

    <xsl:template match="html:*">
        <xsl:element name="{local-name(.)}">
            <xsl:apply-templates select="@*"/>
            <xsl:apply-templates/>
        </xsl:element>
    </xsl:template>

    <xsl:template match="html:html">
        <xsl:element name="html">
            <xsl:apply-templates select="@*"/>
            <xsl:attribute name="lang">
                <xsl:value-of select="$language"/>
            </xsl:attribute>
            <xsl:apply-templates/>
        </xsl:element>
    </xsl:template>

    <xsl:template match="html:link/@href">
        <xsl:attribute name="href">
            <xsl:value-of select="$sharedpath"/>
            <xsl:value-of select="current()"/>
        </xsl:attribute>
    </xsl:template>

    <xsl:template match="html:a/@href[not(starts-with(., '#') or starts-with(., 'http://'))]">
        <xsl:attribute name="href">
            <xsl:value-of select="."/>
            <xsl:value-of select="$extension"/>
        </xsl:attribute>
    </xsl:template>

    <xsl:template match="html:div[@id = 'toc']">
        <div>
            <xsl:apply-templates select="@*"/>
            <h2>
                <xsl:call-template name="string">
                    <xsl:with-param name="id" select="'toc'" />
                </xsl:call-template>
            </h2>
            <ul>
                <xsl:apply-templates select="document('toc.xml')/toc/entry"/>
            </ul>
        </div>
    </xsl:template>

    <xsl:template match="entry">
        <li>
            <a href="{@href}{$extension}">
                <xsl:call-template name="string">
                    <xsl:with-param name="id" select="concat('page_', @id)"/>
                </xsl:call-template>
            </a>
        </li>
    </xsl:template>

    <xsl:template match="x:string">
        <xsl:call-template name="string">
            <xsl:with-param name="id" select="@id"/>
        </xsl:call-template>
    </xsl:template>

    <xsl:template match="x:menu">
        <xsl:call-template name="section">
            <xsl:with-param name="section_type" select="'menu'"/>
        </xsl:call-template>
    </xsl:template>

    <xsl:template match="x:menu/x:menuitem">
        <xsl:call-template name="section-item">
            <xsl:with-param name="section_type" select="'menu'"/>
        </xsl:call-template>
    </xsl:template>

    <xsl:template match="x:optiongroup">
        <xsl:call-template name="section">
            <xsl:with-param name="section_type" select="'option'"/>
            <xsl:with-param name="has_description" select="true()"/>
        </xsl:call-template>
    </xsl:template>

    <xsl:template match="x:optiongroup/x:optiongroup">
        <xsl:call-template name="nested-section">
            <xsl:with-param name="section_type" select="'option'"/>
            <xsl:with-param name="has_description" select="true()"/>
        </xsl:call-template>
    </xsl:template>

    <xsl:template match="x:optiongroup/x:option">
        <xsl:call-template name="section-item">
            <xsl:with-param name="section_type" select="'option'"/>
        </xsl:call-template>
    </xsl:template>

    <xsl:template name="section">
        <xsl:param name="section_type"/>
        <xsl:param name="has_description" select="false()"/>
        <xsl:variable name="full_id" select="concat($section_type, '_', @id)"/>
        <xsl:if test="@id">
            <h3 id="{@id}">
                <xsl:call-template name="string">
                    <xsl:with-param name="id" select="$full_id"/>
                </xsl:call-template>
            </h3>
        </xsl:if>
        <xsl:if test="$has_description and @id">
            <p>
                <xsl:call-template name="string">
                    <xsl:with-param name="id" select="concat($full_id, '_desc')"/>
                </xsl:call-template>
            </p>
        </xsl:if>
        <dl>
            <xsl:apply-templates/>
        </dl>
    </xsl:template>

    <xsl:template name="nested-section">
        <xsl:param name="section_type"/>
        <xsl:param name="has_description" select="false"/>
        <xsl:variable name="full_id">
            <xsl:choose>
                <xsl:when test="../@id">
                    <xsl:value-of select="concat($section_type, '_', ../@id, '_', @id)"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="concat($section_type, '_', @id)"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        <xsl:if test="@id">
            <dt>
                <h4 id="{@id}">
                    <xsl:call-template name="string">
                        <xsl:with-param name="id" select="$full_id"/>
                    </xsl:call-template>
                </h4>
            </dt>
        </xsl:if>
        <dd>
            <p>
                <xsl:if test="$has_description and @id">
                    <xsl:call-template name="string">
                        <xsl:with-param name="id" select="concat($full_id, '_desc')"/>
                    </xsl:call-template>
                </xsl:if>
            </p>
            <dl>
                <xsl:apply-templates/>
            </dl>
        </dd>
    </xsl:template>

    <xsl:template name="section-item">
        <xsl:param name="section_type"/>
        <xsl:variable name="full_id">
            <xsl:value-of select="$section_type"/>
            <xsl:call-template name="ancestor-chain"/>
        </xsl:variable>
        <dt id="{$full_id}">
            <xsl:if test="@after-separator">
                <xsl:attribute name="class">after-separator</xsl:attribute>
            </xsl:if>

            <xsl:call-template name="string">
                <xsl:with-param name="id" select="$full_id"/>
            </xsl:call-template>

            <xsl:if test="@shortcut">
                <small>
                    <xsl:call-template name="string">
                        <xsl:with-param name="id" select="concat($full_id, '_shortcut')"/>
                    </xsl:call-template>
                </small>
            </xsl:if>
        </dt>
        <dd>
            <xsl:call-template name="string">
                <xsl:with-param name="id" select="concat($full_id, '_desc')"/>
            </xsl:call-template>
            <xsl:if test="child::node()">
                <xsl:apply-templates/>
            </xsl:if>
        </dd>
    </xsl:template>

    <xsl:template name="ancestor-chain">
        <xsl:param name="node" select="."/>
        <xsl:if test="namespace-uri($node) = 'urn:x' and $node/@id">
            <xsl:call-template name="ancestor-chain">
                <xsl:with-param name="node" select="$node/.."/>
            </xsl:call-template>
            <xsl:value-of select="concat('_', $node/@id)"/>
        </xsl:if>
    </xsl:template>

    <xsl:template name="string">
        <xsl:param name="id" />
        <xsl:choose>
            <xsl:when test="$strings/x:string[@id = $id]">
                <xsl:apply-templates select="$strings/x:string[@id = $id]/node()"/>
            </xsl:when>
            <xsl:otherwise>
                <span class="missing">MISSING STRING: <xsl:value-of select="$id"/></span>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
</xsl:stylesheet>
